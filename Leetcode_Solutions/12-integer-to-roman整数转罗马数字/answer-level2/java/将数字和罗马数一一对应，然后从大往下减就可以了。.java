### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String intToRoman(int num) {

        int[] nums={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] list={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        StringBuilder buf=new StringBuilder();
        int i=0;
        while(num>0){
            if(num-nums[i]>=0){
                buf.append(list[i]);
                num=num-nums[i];
            }else{
                i++;
            }
        }
        return buf.toString();
    }
}
```