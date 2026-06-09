```
int romanToInt(char * s){
	char A[7] = {'I','V', 'X', 'L', 'C', 'D', 'M'};
    int B[7] = {1, 5, 10, 50, 100, 500, 1000};
    int number = 0;
	while(*s != '\0'){
		for(int i = 0;i < 7;i++){
			if(*s == A[i]){
				if(i == 0 && *(s+1) == 'V'){
						number += 4;
						s++;
						break;
				}else if(i == 0 && *(s+1) == 'X'){
						number += 9;
						s++;
						break;
				}else if(i == 2 && *(s+1) == 'L'){
						number += 40;
						s++;
						break;
				}else if(i == 2 && *(s+1) == 'C'){
						number += 90;
						s++;
						break;
				}else if(i == 4 && *(s+1) == 'D'){
						number += 400;
						s++;
						break;
				}else if(i == 4 && *(s+1) == 'M'){
						number += 900;
						s++;
						break;
				}else{	
					number += B[i];
					break;
				}
			} 
		}
		s++;
	}
	return number;
}

```
