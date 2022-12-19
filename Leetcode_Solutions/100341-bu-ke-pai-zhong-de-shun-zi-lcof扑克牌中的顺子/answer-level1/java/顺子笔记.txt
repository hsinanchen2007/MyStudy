### 解题思路
首选对于乱序的数组应该先排序，然后判断大小王的个数，除去大小王后生成一个不存在大小王的数组，对这个数组进行相临数比较，
相临数差值有可能等于0，有可能等于1，也有可能大于1，顺子的条件是相临的两个数都差1，并且王可能替代任何位置的数，这可以换一种理解方式，就是要么数组里面相临值是1，要么他们的中间差的位置小于等于王的个数，其中差值为0的时候是个坑，前两次都没有考虑到

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
quickSort(nums,0,nums.length-1);

        int zeroCount = getZeroCount(nums);
        boolean isTrue = true;
        if(zeroCount!=0){
            int[] noZeroArray = new int[nums.length-zeroCount];
            System.out.println(nums.length-zeroCount);
            System.arraycopy(nums,zeroCount,noZeroArray,0,nums.length-zeroCount);
        
            for (int i = noZeroArray.length-1; i >0 ; i--) {
                int chazhi =   noZeroArray[i]-noZeroArray[i-1];
                if(chazhi ==1){
                    continue;
                }else if(chazhi-1>0&&chazhi-1<=zeroCount){
                        zeroCount =zeroCount- chazhi+1;
                    }else{
                        isTrue = false;
                    }
                
            }
        }else{
            for (int i = nums.length-1; i >0 ; i--) {
                int chazhi =   nums[i]-nums[i-1];
                if(chazhi ==1){
                    continue;
                }else{
                    
                        isTrue = false;
                    
                }
            }
        }
        return isTrue;
    }

    public int getZeroCount(int[] nums){
        int count = 0;

        for(int i = 0;i<nums.length;i++){
            if(nums[i]<=0){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
 public void quickSort(int[] array,int left,int right){
        if(left>=right){
            return;
        }
        int i = left;
        int j = right;
        int temp = array[left];
        while(i!=j){
            while(array[j]>=temp&&j>i){
                j--;
            }
            while(array[i]<=temp&&j>i){
                i++;
            }
            if(j>i){
                int temp1 = array[i];
                array[i] = array[j];
                array[j] = temp1;
            }else{
                array[left] = array[i];
                array[i] = temp;
            }
        }

        quickSort(array, left, i-1);
        quickSort(array, i+1, right);

    }
}
```