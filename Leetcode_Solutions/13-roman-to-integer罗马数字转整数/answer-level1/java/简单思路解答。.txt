### 解题思路
思路比较简单:
1.遍历s的所有字母把对应的数字加到sum上;
2.在检测一下字符串s中是否含有{"CM","CD","XC","XL","IX","IV"}这种特殊的，如果有的话再减去jian={200,200,20,20,2,2}中对应的数字；
欢迎指导；

### 代码

```java
class Solution {
    public int romanToInt(String s) {
      String[] roman1={"M","D","C","L","X","V","I"};
            int[] nums={1000,500,100,50,10,5,1};
            String[] roman2={"CM","CD","XC","XL","IX","IV"};
            int[] jian={200,200,20,20,2,2};//因为sum都加过一次，所以与真正的数差相应的二倍
            int sum=0;
            for(int i=0;i<s.length();i++)
            {   String c=s.charAt(i)+"";
                for(int j=0;j<7;j++) {
                    if (c.equals(roman1[j])) sum = sum + nums[j];
                }
            }
        for(int j=0;j<6;j++) {
            if (s.contains(roman2[j])) sum = sum - jian[j];
        }
     return sum;
      
    }
}
```