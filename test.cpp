//snippet-sourcedescription:[create_bucket.cpp demonstrates how to create an Amazon S3 bucket.]
//snippet-keyword:[C++]
//snippet-keyword:[Code Sample]
//snippet-keyword:[Amazon S3]
//snippet-service:[s3]
//snippet-sourcetype:[full-example]
//snippet-sourcedate:[]
//snippet-sourceauthor:[AWS]


/*
   Copyright 2010-2019 Amazon.com, Inc. or its affiliates. All Rights Reserved.
   This file is licensed under the Apache License, Version 2.0 (the "License").
   You may not use this file except in compliance with the License. A copy of
   the License is located at
    http://aws.amazon.com/apache2.0/
   This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied. See the License for the
   specific language governing permissions and limitations under the License.
*/
//snippet-start:[s3.cpp.create_bucket.inc]
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/CreateBucketRequest.h>
//snippet-end:[s3.cpp.create_bucket.inc]

/**
 * Create an Amazon S3 bucket.
 */
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "create_bucket - create an S3 bucket" << std::endl
            << "\nUsage:" << std::endl
            << "  create_bucket <bucket>" << std::endl
            << "\nWhere:" << std::endl
            << "  bucket - the bucket to create" << std::endl
            << "\nExample:" << std::endl
            << "  create_bucket testbucket\n" << std::endl << std::endl;
        exit(1);
    }

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        const Aws::String bucket_name = argv[1];

        std::cout << "Creating S3 bucket: " << bucket_name << std::endl;

        // snippet-start:[s3.cpp.create_bucket.code]
        Aws::S3::S3Client s3_client;

        Aws::S3::Model::CreateBucketRequest request;
        request.SetBucket(bucket_name);

        auto outcome = s3_client.CreateBucket(request);

        if (outcome.IsSuccess())
        {
            std::cout << "Done!" << std::endl;
        }
        else
        {
            std::cout << "CreateBucket error: "
                << outcome.GetError().GetExceptionName() << std::endl
                << outcome.GetError().GetMessage() << std::endl;
        }
        // snippet-end:[s3.cpp.create_bucket.code]
    }
    Aws::ShutdownAPI(options);
}
