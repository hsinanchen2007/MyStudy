熟悉的配方，熟悉的味道，回想“2.两数之和”和“15.三数之和”分别是如何计算的。这里我的思路是将二者相结合形参这道“四数之和”的算法：1.因为需要用到双指针法，所以先将数组排序。2. 遍历数组每个元素nums[i]的时候计算其于target的差值temp（这里有点两数之和的味道）。3. 同时在nums[i]元素后面的部分寻找是否有三个数相加等于temp（这里就是进行双指针法解三数之和，具体思路参考[徒手挖地球六周目](https://jerrymouse1998.github.io/post/%E5%BE%92%E6%89%8B%E6%8C%96%E5%9C%B0%E7%90%83%E5%85%AD%E5%91%A8%E7%9B%AE/)中的三数之和双指针法思路），如果找到三数和等于temp就将这三个数和nums[i]加入结果集。5. 在nums[i]元素后面的部分进行双指针法全部遍历完后，对nums[i+1]进行上述操作，直至数组中所有元素都进行完毕。

和"三数之和"一样需要"**去重**"：1. 外层for遍历每个元素nums[i]时，除了0号元素之外如果nums[i]\=\=nums[i+1]，则需要跳过。2. 内层循环除了第一个元素之外，如果nums[j]\=\=nums[j+1],也需要跳过。

可以**优化**的地方：1. 固定当前nums[i]元素后，最小的四数之和已经大于target，则结束循环。2.固定当前nums[i]元素后，当前最大的四数之和依然小于target，则跳过当前元素，进行下一个元素nums[i+1]。

```java
public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        int len=nums.length;
        if (nums==null||len<4)return ans;
//        排序
        Arrays.sort(nums);

//        遍历数组每一个元素,因为是求四数之和，所以i<len-3
        for (int i=0;i<len-3;i++){
//            如果当前最小的四数之和已经大于target，则结束循环
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]> target)break;
//            如果当前最大的四数之和依然小于target，则跳过当前元素，进行下一个元素
            if (nums[i]+nums[len-1]+nums[len-2]+nums[len-3]< target)continue;
//            跳过重复的元素
            if (i>0&&nums[i]==nums[i-1])continue;
//            当前数组想要组成target所需要的值
            int temp=target-nums[i];
            
//            遍历i号元素后面部分的每个元素，因为是求三数之和，所以i<len-2
            for (int j=i+1;j<len-2;j++){
//                跳过重复元素
                if (j>i+1&&nums[j]==nums[j-1])continue;
//                用双指针分别指向j号元素后面部分的开始元素和结尾元素
                int L=j+1,R=len-1;
                while (L<R){
                    int sum=nums[j]+nums[L]+nums[R];
                    if (sum==temp){
                        ans.add(Arrays.asList(nums[i],nums[j],nums[L],nums[R]));
                        while (L<R&&nums[L]==nums[L+1])L++;
                        while (L<R&&nums[R]==nums[R-1])R--;
                        L++;
                        R--;
                    }else if (sum<temp){
                        L++;
                    }else if (sum>temp){
                        R--;
                    }
                }
            }
        }
        return ans;
    }
```

时间复杂度：O(n^3)