### 解题思路
![2019121702.PNG](https://pic.leetcode-cn.com/656c8a1bf02c6d3eb7cf6f729df8f1278621297ef939702859ff0876250831b8-2019121702.PNG)
![2019121701.PNG](https://pic.leetcode-cn.com/72db9978e3db1d49d9e75fdd355848e5f005a0aa19eb1ddfd7c1cf1c23196b45-2019121701.PNG)
此处撰写解题思路
---对0的个数进行计数,存在以下情况:
-----1.数组长度大于2://1)从头连续出现0;2)最后几个数到末尾连续出现0;3)中间出现连续的0;4)从头至尾都是0 //对1),2),3),4)这四情形下分别计算可种植数目.
-----2.数组长度为1,则判断该元素是否为0,若为0,可以种一棵树.
-----3.数组长度为2,则判断这两个元素是否同时为0,若两个元素同时为0,可以种一棵树.

### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
    	int i = 0;
    	int count = 0;
    	int j = 0;
    	boolean active = true;
    	if(flowerbed.length>2) {
        	while(j<flowerbed.length) {
        		if(flowerbed[j]==0) {
        			i++;
        			j++;
        		}else if(flowerbed[j]!=0) {
        			if(active) {
        				if(i>=2) {
        					count = count +i/2;
        				}
        			}else {
            			if(i==3) {
            				count++;
            			}
            			if(i>3) {
            				i = i-3;
            				count = count + 1 +i/2;
            			}
        			}
        			active = false;
        			i = 0;
        			j++;
        		}
        	}
        	if(active) {
        		count += (i+1)/2;
        	}else {
        		if(i>=2) {
        			count = count +i/2;
        		}
        	}
    	}
    	if(flowerbed.length==2) {
    		if(flowerbed[0]==0&&flowerbed[1]==0) {
    			count ++;
    		}
    	}
        if(flowerbed.length==1){
            if(flowerbed[0]==0){
                count++;
            }
        }    	
        return count>=n;
    }
}
```