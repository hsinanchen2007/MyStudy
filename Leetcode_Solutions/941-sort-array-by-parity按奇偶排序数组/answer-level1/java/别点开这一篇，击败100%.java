### 解题思路
先遍历一遍，将偶数放在ans前面，将奇数放在临时数组temp中

在遍历temp，将temp中的奇数放在ans中

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {

        int[] ans = new int[A.length];

        int[] temp = new int[A.length];

        int index = 0, indexTemp = 0;
        for(int num : A){
            if(num % 2 == 0){
                ans[index++] = num;
            }else{
                temp[indexTemp++] = num;
            }
        }

        for(int i = 0; i < indexTemp; i++){
            ans[index++] = temp[i];
        }

        return ans;

    }
}
```