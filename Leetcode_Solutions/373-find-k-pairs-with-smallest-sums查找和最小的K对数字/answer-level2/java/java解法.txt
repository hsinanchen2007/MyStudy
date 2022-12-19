执行用时 : 67 ms, 击败了42.05% 的用户
内存消耗 : 45.6 MB, 击败了61.33% 的用户
```
class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<int[]> list = new ArrayList<>();
        if(k <= 0){
            return list;
        }
        P:for(int i = 0; i < nums1.length; i++){
            for(int j = 0; j < nums2.length; j++){
                int[] z = new int[]{nums1[i], nums2[j]};
                if(list.isEmpty()){
                    list.add(z);
                }else{
                    boolean flag = true;//当前这对数字和是否排在第k位后面
                    for(int q = 0; q < list.size(); q++){
                        if(list.get(q)[0] + list.get(q)[1] > z[0] + z[1]){
                            list.add(q,z);
                            flag = false;
                            break;
                        }
                    }
                    if(list.size()> k){
                        list.remove(list.size()-1);
                    }else if(list.size() < k){
                        if(flag){
                            list.add(z);
                        }
                    }else{
                        if(flag){
                            //当前这对数字和排在第k位后面，由于数组是升序的，
                            //后面的数字肯定也排在k后面，故可跳出循环
                            continue P;
                        }
                    }
                }
            }
        }
        return list;
    }
}
```