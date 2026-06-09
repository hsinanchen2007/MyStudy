### 解题思路
遍历数组，找到可能的最大值max与n比较，
max<n false
max>n true

### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int num =flowerbed.length;
        int i;
        int max = 0;
        if(num==1){
            if(flowerbed[0]==0)
            max++;
        }
        else if(num==2){
            if(flowerbed[0]==0&&flowerbed[1]==0)
            max++;
        }
        else{
            for(i=0;i<num;i++){
            if(flowerbed[i]==0){
                if(i==0){
                    if(flowerbed[i+1]==0){
                        max++;
                        flowerbed[i]=1;
                    }
                }

                if(i==num-1){
                    if(flowerbed[i-1]==0){
                        max++;
                        flowerbed[i]=1;
                    }
                }
                if(i!=0&&i!=num-1){
                    if(flowerbed[i+1]==0&&flowerbed[i-1]==0){
                        max++;
                        flowerbed[i]=1;
                    }
                }
            }
        }
        

        }
        if(max<n){
            return false;
        }else {
            return true;
        }
        
    }
}
```