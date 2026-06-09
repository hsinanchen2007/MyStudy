### 解题思路
1、假设在任意索引i位置处有所有的上升子序列dpList   我们用List<List<Integer>> lastDpList来表示。
     
2、那么对于当前索引位置i,存在
       int num = nums[i];
       //以i位置结尾的上升序列
       List<List<Integer>>  newDpList = new ArrayList<List<Integer>>();
       for(List<Integer> dpList:lastDpList){
                if(num>dpList.getLast()){
                        dpList.add(num);
                }else{
                        //说明当前位置的num处于原来的上升序列的中间位置
                        //相当于形成了两个子序列
                        //例如1 3 6 7 9 碰到4
                        //形成1 3 4和
                        //1  3 6 7 9 
                       //我们用一个新的子序列列表来保存
                       List<Integer> newList = new ArrayList<Integer>();
                        for(int i:dpList){
                                if(i<num){
                                        newList.add(i);
                                }
                        }
                        newList.add(num);
                        newDpList.add(newList);
                }
       } 
       //这时候我们有一份原来的所有上升子序列列表lastDpList，和当前位置以nums[i]结尾的上升子序列列表。
      //由于题目是要求最长上升子序列
     //所以我们首先对当前位置以nums[i]结尾的上升子序列列表求一个最大长度的子序列
           List<Integer> currentLongestList = newDpList.stream.max((list1,list2)->Integer.valueOf(list1.size()).compareTo(list2.size())).get();
            //再将原来lastDpList里所有长度小于currentLongestList的list删掉.
            //因为如果nums[i+1]加入不进去currentLongestList中，也必然加入不进去以前未包含nums[i]的列表中.
            for(List<Integer> dpList:lastDpList){
                    if(dpList.size()<currentLongestList.size()){
                            //dpList删掉
                    }
            }
            //最后再将currentLongestList加入到lastDpList中
            //maxLength就是求最后所有lastDpList的最大长度

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
      if(nums==null || nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return 1;
        }
        //lastDpList表示截止到当前位置之前的升序列
        List<LinkedList<Integer>> lastDpList = new ArrayList<LinkedList<Integer>>();
        LinkedList<Integer> dp0List = new LinkedList<>();
        dp0List.add(nums[0]);
        lastDpList.add(dp0List);
        //dp[i+1]
        int lastIndex = nums.length-1;
        int maxLength = 0;
        for(int i = 1;i<=lastIndex;i++){
            int currentNum = nums[i];
            List<LinkedList<Integer>> newAppendList = new ArrayList<>();
            for(LinkedList<Integer> dpList : lastDpList){
                if(currentNum>dpList.getLast()){
                    dpList.add(currentNum);
                }else{
                    //找到currentNum在dpList的位置，将dpList分为两个list,一个是原来的，一个是从dpList开始直到找到所有比currentNum小的元素组成一个新的list
                    LinkedList<Integer> newDpList = new LinkedList<>();
                    for(Integer num : dpList){
                        if(num<currentNum){
                            newDpList.add(num);
                        }
                    }
                    newDpList.add(currentNum);
                    newAppendList.add(newDpList);
                }
            }
            //寻找newAppendList里面长度最长的一个list
            if(!newAppendList.isEmpty()){
                LinkedList<Integer> mostLongestDpList = newAppendList.stream().max((list1, list2) -> Integer.valueOf(list1.size()).compareTo(Integer.valueOf(list2.size()))).get();
                List<LinkedList<Integer>> removeList = new ArrayList<>();
                for(LinkedList<Integer> dpList : lastDpList){
                    if(dpList.size()<=mostLongestDpList.size()){
                        removeList.add(dpList);
                    }
                }
                lastDpList.removeAll(removeList);
                lastDpList.add(mostLongestDpList);
            }
        }
        if(!lastDpList.isEmpty()){
            for(LinkedList<Integer> dpList:lastDpList){
                maxLength = Math.max(maxLength,dpList.size());
            }
        }
        return maxLength;
    }
}
```