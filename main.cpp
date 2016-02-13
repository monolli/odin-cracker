#include <iostream>
#include <openssl/md5.h>
#include <string>
#include <fstream>
#include <time.h>
#include <cstring>
#include <stdio.h>

using namespace std;

ifstream input("md5_pss_hash.txt");
string line,str=" ";
char try1[8];
int tam=0,done=0;
time_t start,end;
unsigned char digest[16];
char string_x[10];

int main()
{
	JMP:
	while(getline(input,line)){														//get the lines from the .txt
		time (&start);																//start the timer as soon as there is a target hash
		while(done==0){
			for(int p=32;p<127;p++){												//go through characters in the last position
				if(tam>=7){		
					try1[7]=p;														//change de value of the last position
				}
				for(int o=32;o<127;o++){											//go through characters in the 7th position
					if(tam>=6){					
						try1[6]=o;													//change de value of the 7th position
					}
					for(int n=32;n<127;n++){										//go through characters in the 6th position
						if(tam>=5){		
							try1[5]=n;												//change de value of the 6th position
						}
						for(int m=32;m<127;m++){									//go through characters in the 5th position
							if(tam>=4){					
								try1[4]=m;											//change de value of the 5th position
							}
							for(int l=32;l<127;l++){								//go through characters in the 4th position
								if(tam>=3){					
									try1[3]=l;										//change de value of the 4th position
								}
								for(int k=32;k<127;k++){							//go through characters in the 3rd position
									if(tam>=2){			
										try1[2]=k;									//change de value of the 3rd position
									}
									for(int j=32;j<127;j++){						//go through characters in the 2nd position
										if(tam>=1){	
											try1[1]=j;								//change de value of the 2nd position
										}
										for(int i=32;i<127;i++){								//go through characters in the 1st position
												try1[0]=i;										//change the 1st position	
												str=try1;										//convert from char array to string
												strcpy(string_x, str.c_str());					//convert the string to array char
												MD5_CTX ctx;									//create the MD5 hash and store at mdString
												MD5_Init(&ctx);
												MD5_Update(&ctx, string_x, strlen(string_x));
												MD5_Final(digest, &ctx);
												char mdString[33];
												for (int i = 0; i < 16; i++){
													sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
												}
												if(std::string(mdString)==line){				//compare the generated has with the target one
													time (&end);								//if they are equal print, stop timer, and go to the next password
													double dif = difftime (end,start);
													cout<<"Password: "<<str<<" Time: "<<dif<<" s"<<endl;
													cout<<"Original: "<<line<<endl;
													cout<<"Cracked:  "<<mdString<<endl<<endl;
													goto JMP;
												}
										}
										if(tam==0){
											tam++;
										}
									}
									if(tam==1){
										tam++;
									}
								}
								if(tam==2){
									tam++;
								}
							}
							if(tam==3){
								tam++;
							}
						}
						if(tam==4){
							tam++;
						}
					}
					if(tam==5){
						tam++;
					}
				}
				if(tam==6){
					tam++;
				}
			}
			if(tam==7){
				goto JMP;
				cout<<"Password bigger than 8"<<endl<<endl;			//could not find the password
			}	
		}
	}
	
	return 0;
}
