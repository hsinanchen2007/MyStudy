![2020022401.PNG](https://pic.leetcode-cn.com/410d1766e9fa9cf314eb15020221710529761351ab4397f7ef6050a891ccb3a2-2020022401.PNG)
### 解题思路
//巧利用num的范围是[0,10^4],说明num最大值是9999,
//因此,可以设置一个temp=1000,然后用num对temp进行取余和取整操作;
//用num对temp不断取整(记为n),判断n是否为9;
//若n=9,则num=num%temp,temp=temp/10,继续循环;
//若n=6,则将6变换为9,终止循环;
### 代码
```java
class Solution {
    public int maximum69Number (int num) {
    	int temp = 1000;
    	int out = 0;
    	while(num>0) {
    		if(num/temp==9) {
    			out += temp*9;
    			num = num%temp;
    			temp = temp/10;
    		}else if(num/temp==6) {
    			out += temp*9;
    			num = num%temp;
    			temp = temp/10;
    			break;
    		}else if(num/temp==0) {
    			temp=temp/10;
    		}
    		
    	}
    	out += num;
    	return out;
    }
}
```