
排序后，递归使用二分查找，不断右移数组操作范围的左边界，直至范围为空。
在每一轮查找中，将本轮范围内左边界比较大的那个数组的左边界作为查找对象，在另一个数组中查找，并根据查找对象出现的次数加入到结果集中。查找结束后，调整数组范围的左边界，将已查找过的元素排除在范围之外，进行下一轮查找。
代码逻辑读起来有点绕， 感觉还可以再优化。期待更好的二分法实现代码。
执行用时2ms 已经战胜 99.90 % 的 java 提交记录
内存36.5 MB

class Solution {
    
    public int[] intersect(int[] nums1, int[] nums2) {
        
        if(nums1.length ==0 || nums2.length ==0 )
            return new int[0];
        List<Integer> result = new ArrayList<Integer>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        //根据nums1和nums2最小元素的大小来调换参数，调用递归查找方法
        if(nums1[0] > nums2[0])
           findInRange(nums1, 0, nums2, 0, result);
        else
           findInRange(nums2, 0, nums1, 0, result);
        return convertListToArray(result);
    }

    //假定nums1[start1] > nums2[start2] （可以通过调换传入的参数，使得此假定一定成立）
    public void findInRange(int[] nums1, int start1, int[] nums2, int start2, List<Integer> result) {
        //完全无交集的情况，直接返回
        if(nums2[nums2.length-1]<nums1[start1]){
            return;
        }

        //nums1[start1]的大小一定在nums2的第start2个元素和最后一个元素之间， 把nums1[start1]作为搜索目标
        int toFind = nums1[start1];
        //使用二分法找到nums2中第一个大于toFind的位置，这个位置就是left， 
        //并在此过程中把toFind在nums2中出现的次数算出
        int left = start2;
        int right = nums2.length-1;
        int times2 = 0;
        while(left<=right){
            int half = (left+right)/2;
            if(nums2[half]==toFind){
                    //向左统计toFind出现的次数
                    int backfind = half-1;
                    while(backfind>=left && nums2[backfind]==toFind){
                        backfind --;
                        times2++;
                    }
                    //向右统计toFind出现的次数，并将left置为第一个大于toFind的位置后，结束查找
                    while(half<=right && nums2[half]==toFind){
                        half ++;
                        times2++;
                    }
                    left = half;
                    break;
            }else if(nums2[half]>toFind)
                right =  half-1;
            else{
                left = half+1;
            }
        }
        //根据toFind在nums2中出现的次数和在nums1中出现的次数，来确定要将其加入几次到结果集中
        int times1 = 0;
        while(start1<nums1.length && toFind == nums1[start1]){
            start1 ++;
            times1 ++;
            if(times1<=times2)
                result.add(toFind);
        }

        //更新下一个要查找的位置
        int newStart1 = start1;
        int newStart2 = left;

        //所有元素查找完毕，退出递归
        if(nums1.length == newStart1
          ||nums2.length == newStart2)
            return;

        //递归调用本方法， 进行下一轮迭代
        if(nums1[newStart1] > nums2[newStart2])
           findInRange(nums1, newStart1, nums2, newStart2, result);
        else
           findInRange(nums2, newStart2, nums1, newStart1, result);
    }
    
    
    public int[] convertListToArray(List<Integer> integers)
    {
        int[] ret = new int[integers.size()];
        for (int i=0; i < ret.length; i++)
        {
            ret[i] = integers.get(i).intValue();
        }
        return ret;
    }
}
