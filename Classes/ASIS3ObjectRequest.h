//
//  ASIS3ObjectRequest.h
//  Part of ASIHTTPRequest -> http://allseeing-i.com/ASIHTTPRequest
//
//  Created by Ben Copsey on 16/03/2010.
//  Copyright 2010 All-Seeing Interactive. All rights reserved.
//
//  Use this class to fetch, upload, copy and delete objects on Amazon S3

#import <Foundation/Foundation.h>
#import "ASIS3Request.h"


@interface ASIS3ObjectRequest : ASIS3Request {

	// Name of the bucket to talk to
	NSString *bucket;
	
	// Key of the resource you want to access on S3
	NSString *key;
	
	// The bucket + path of the object to be copied (used with COPYRequestFromBucket:path:toBucket:path:)
	NSString *sourceBucket;
	NSString *sourceKey;
	
	// The mime type of the content for PUT requests
	// Set this if having the correct mime type returned to you when you GET the data is important (eg it will be served by a web-server)
	// Will be set to 'application/octet-stream' otherwise in iPhone apps, or autodetected on Mac OS X
	NSString *mimeType;
}

// Create a request, building an appropriate url
+ (id)requestWithBucket:(NSString *)bucket key:(NSString *)key;

// Create a request for an object, passing a parameter in the query string
// You'll need to parse the response XML yourself
// Examples:
// Fetch ACL:
// ASIS3ObjectRequest *request = [ASIS3ObjectRequest requestWithBucket:@"mybucket" key:@"my-key" parameter:@"acl"];
// Get object torret:
// ASIS3ObjectRequest *request = [ASIS3ObjectRequest requestWithBucket:@"mybucket" key:@"my-key" parameter:@"torrent"];
// See the S3 REST API docs for more information about the parameters you can pass
+ (id)requestWithBucket:(NSString *)bucket key:(NSString *)key subResource:(NSString *)subResource;


// Create a PUT request using the file at filePath as the body
+ (id)PUTRequestForFile:(NSString *)filePath withBucket:(NSString *)bucket key:(NSString *)key;

// Create a PUT request using the supplied NSData as the body (set the mime-type manually with setMimeType: if necessary)
+ (id)PUTRequestForData:(NSData *)data withBucket:(NSString *)bucket key:(NSString *)key;

// Create a DELETE request for the object at path
+ (id)DELETERequestWithBucket:(NSString *)bucket key:(NSString *)key;

// Create a PUT request to copy an object from one location to another
// Clang will complain because it thinks this method should return an object with +1 retain :(
+ (id)COPYRequestFromBucket:(NSString *)sourceBucket key:(NSString *)sourceKey toBucket:(NSString *)bucket key:(NSString *)key;

// Creates a HEAD request for the object at path
+ (id)HEADRequestWithBucket:(NSString *)bucket key:(NSString *)key;

@property (retain) NSString *bucket;
@property (retain) NSString *key;
@property (retain) NSString *sourceBucket;
@property (retain) NSString *sourceKey;
@property (retain) NSString *mimeType;

@end