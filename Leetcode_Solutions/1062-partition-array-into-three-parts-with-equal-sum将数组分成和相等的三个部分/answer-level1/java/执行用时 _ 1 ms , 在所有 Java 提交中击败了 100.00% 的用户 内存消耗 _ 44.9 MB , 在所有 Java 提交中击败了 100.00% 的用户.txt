### 解题思路
只需要确认前两部分是否相等且等于总和的三分之一，再判断是否存在第三部分即可

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        int len = A.length;
        if(len < 3){
            return false;
        }else{
            int nums = 0;
            for(int i = 0; i < len;i++){
                nums += A[i];
            }

            if(nums % 3 != 0){
                return false;
            }else{
                int oneNum = 0;
                int next = 0;
                int c = 0;
                int start = next;
                for(int j = start;j<len;j++){
                    next = j;
                    oneNum += A[j];
                    if(oneNum == nums/3){
                        c ++;
                        break;
                    }
                }
                start = next + 1;
                oneNum = 0;
                for(int j = start;j<len;j++){
                    next = j;
                    oneNum += A[j];
                    if(oneNum == nums/3){
                        c ++;
                        break;
                    }
                }
                if(next >= len-1){
                    return false;
                }
                
                if(c == 2){
                    return true;
                }else{
                    return false;
                }
            }

            
        }
        

    }
}
```