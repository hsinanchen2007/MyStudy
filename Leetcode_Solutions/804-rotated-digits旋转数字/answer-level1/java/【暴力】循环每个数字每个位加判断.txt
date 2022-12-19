### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rotatedDigits(int N) {
        int sum=0;
		for(int i=0;i<=N;i++) {
        	int flag=0;
        	int temp=i;
        	while(temp!=0) {
        		if(temp%10==3||temp%10==4||temp%10==7) {
        			flag=1;
        			break;
        		}
        		if(temp%10==2||temp%10==5||temp%10==6||temp%10==9) {
        			flag=2;
        		}
        		temp/=10;
        	}
        	if(flag==2) {
        		sum++;
        	}
        }
        return sum;
    }
}
```