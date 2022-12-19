# 由于解法比较简单，长得帅的可以不看注释
** 例：2753 
index先存7这个点的参数，再去在"53"中找比2大的最小数，找到后是3，将2和3交换就成了3752，在将"752"排序"257" 
    结果：3257
**

```
public void nextPermutation(int[] nums) {
        int[] index = new int[2];  //index[0]存值，index[1]存该值对应的坐标，默认值
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                index[0] = nums[i];  //初始存后面比较的时候用
                index[1] = i;
                //找出[i,length)中大于nums[i-1]的最小数,更新index            
                for (int j = i + 1; j < nums.length; j++) {   //j从i+1的原因是i已经用在index初始化了，
                    if (nums[j] > nums[i - 1] && nums[j] < index[0]) {  //大于nums[i-1] 小于nums[i]的最小数（index默认值就是nums[i]的参数）
                        index[0] = nums[j]; //更新index，
                        index[1] = j;
                    }
                }
                //交换nums[i-1]和[i,length)中大于nums[i-1]的最小数
                int tem = nums[i - 1];
                nums[i - 1] = nums[index[1]];
                nums[index[1]] = tem;
                //将[i,length)这部分进行排序
                Arrays.sort(nums, i, nums.length);
                break;
            }
            //这里注意：i等于1时，如果能改,上面就break了。能执行到这里说明无法找到比原先大的数例如54321
            if (i == 1) {
                Arrays.sort(nums);
            }
        }
    }
```
