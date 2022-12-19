![2020032302.PNG](https://pic.leetcode-cn.com/aab99c2ab4665aa002f93e6042361817bb94684d407718c5d7a264d627358f86-2020032302.PNG)

### 解题思路
注: 若需要插入数字的当前已填充有数字, 则需要将当前已填的数字以及该数字后面的所有数字往后顺序移动, 将该位置空出来, 然后将新值赋给该空位置

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] out = new int[nums.length];
        Arrays.fill(out,-1);
        int avaIndex = 0;
        int i=0;
        int j=0;
        while(i<nums.length){
            if(out[index[i]]==-1){
                out[index[i]] = nums[i];
            }else{
                if(avaIndex==0){
                    for(j=index[i]+1;j<index.length;j++){
                        if(out[j]==-1){
                            avaIndex=j;
                            break;
                        }
                    }
                }else{
                    j=avaIndex+1;
                    while(j<index.length){
                        if(out[j]==-1){
                            avaIndex=j;
                            break;
                        }
                        j++;
                    } 
                }
                j=avaIndex;
                while(j>index[i]){
                    out[j] = out[j-1];
                    j--;
                }
                out[index[i]] = nums[i];
            }
            i++;
        }
        return out;
    }
}
```