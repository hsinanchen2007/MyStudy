### 解题思路
分出正负并排序
先处理3个0的情况
查询正数的时候去二分查找
两个负数相加 一个正数
两个非负数相加 一个负数

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //分出正负并排序
        List<Integer> fu = new ArrayList();
        List<Integer> zheng = new ArrayList();
        int countZero = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] < 0){
                fu.add(nums[i]);
            } else {
                if(nums[i]==0){
                    countZero++;
                }
                zheng.add(nums[i]);
            }
        }
        fu.sort((a,b)->a-b);
        zheng.sort((a,b)->a-b);

        List<List<Integer>> resList = new ArrayList();
        List<Integer> tempList = null;
        //3个0的情况
        if(countZero >=3){
            tempList = Arrays.asList(0,0,0);
            resList.add(tempList);
        }
        int min = -1<<31;
        int max = (1<<31)-1;
        //两个负数相加 一个正数
        for(int i=0;i<fu.size()-1;i++){
            int temp1 = fu.get(i);
            int limit = min-temp1;
            for(int j =i+1 ;j<fu.size();j++){
                int temp2 = fu.get(j);
                //防溢出
                if(limit < fu.get(j)){
                    int res = midFind(zheng, temp1+fu.get(j));
                    if(res >= 0){
                        tempList = new ArrayList();
                        tempList.add(temp1);
                        tempList.add(temp2);
                        tempList.add(zheng.get(res));
                        resList.add(tempList);
                    }
                }
                //如果下一个和这个一样大就防止重复跳过
                while(j<fu.size()-1 && fu.get(j+1) == temp2){
                    j++;
                }
            }
            //如果下一个和这个一样大就防止重复跳过
            while(i<fu.size()-1 && fu.get(i+1) == temp1){
                    i++;
            }
        }

        //两个非负数相加 一个负数
        for(int i=0;i<zheng.size()-1;i++){
            int temp1 = zheng.get(i);
            int limit = max-temp1;
            for(int j =i+1 ;j<zheng.size();j++){
                int temp2 = zheng.get(j);
                //防溢出
                if(limit > zheng.get(j)){
                    int res = midFind(fu, temp1+zheng.get(j));
                    if(res >= 0){
                        tempList = new ArrayList();
                        tempList.add(fu.get(res));
                        tempList.add(temp1);
                        tempList.add(temp2);
                        resList.add(tempList);
                    }
                }
                //如果下一个和这个一样大就防止重复跳过
                while(j<zheng.size()-1 && zheng.get(j+1) == temp2){
                    j++;
                }
            }
            //如果下一个和这个一样大就防止重复跳过
            while(i<zheng.size()-1 && zheng.get(i+1) == temp1){
                    i++;
            }
        }
        resList.sort((a,b)->a.get(0)-b.get(0));
        return resList;
    }

    public int midFind(List<Integer> a, int find){
        int left = 0;
        int right = a.size()-1;
        int mid = (left + right)/2;
        find = 0 -find;
        boolean flag = find > 0;
        while(left <= right){
             if (find == a.get(mid)) {
                return mid;
            } else if (find > a.get(mid)) {
                left = mid + 1;
            } else if (find < a.get(mid)) {
                right = mid - 1;
            }
            mid = (right+left)/2;
        }
        return -1;
    }
}
```