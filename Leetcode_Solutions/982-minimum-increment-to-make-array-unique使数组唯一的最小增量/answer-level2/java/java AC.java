### 解题思路


### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] bloom = new int[80000];
        int ans=0;
        for(int a: A){
            bloom[a]+=1; //记录每个元素出现次数
        }

        for(int i=0;i<bloom.length;i++){
            while(bloom[i]>1){ //如果有冗余的元素
                for(int j=i+1;j<bloom.length;j++){//找出最近的一个空位
                    if(bloom[j]==0){ //填空位
                        bloom[j]+=1;
                        bloom[i]-=1;
                        ans+= j-i;
                        break;
                    }
                }
            }
        }

        return ans;
    }
}
```