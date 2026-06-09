### 解题思路
1.排除全为9的情况，如果全为9，定义新数组，第0位赋值为1，返回答案
2.不全为9时，数组长度不会变，从数组最后一个向前遍历，当某位小于9时，此位加1返回即可，若为9，则将此位置为0，继续向前遍历

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {

        boolean flag=true;//用于判断是否全为9，否为false
        for(int i=0;i<digits.length;i++){
            if(digits[i]!=9){
                flag=false;break;//发现一个不为9时就置为false，跳出循环
            }
        }

        if(flag){//全为9时定义新数组，长度比传入数组长度多一位，首位赋值为1，其余位会默认为0
            int[]ans=new int[digits.length+1];
            ans[0]=1;
            return ans;
        }else{//传入数组不全为9时
            for(int i=digits.length-1;i>=0;i--){//从右向左遍历
                if(digits[i]<9){//小于9时加1返回
                    digits[i]=digits[i]+1;return digits;
                }else{//等于9时，此位置0，继续遍历
                    digits[i]=0;
                }
            }
        }
        return digits;
    }
}
```