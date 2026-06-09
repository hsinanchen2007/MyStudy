### 解题思路
此处撰写解题思路
1.每次取数组中两最小值相加
2.将值放回数组中
3.重复1，2步骤至数组中只有一个值
难点应该是第2步，可以使用两个Linkedlist来代替数组。表述能力太差，不写了- -！，有问题再说
### 代码

```java
class Solution {
    public int connectSticks(int[] sticks) {
        int ans =0;
        Arrays.sort(sticks);
        LinkedList<Integer> l1 = new LinkedList();
        LinkedList<Integer> l2 = new LinkedList();
        for(int i=0;i<sticks.length;i++){
            l1.add(sticks[i]);
        }
        while(l1.size()+l2.size()!=1){
            if(l2.size()==0){
                int tmp1 = l1.removeFirst();
                int tmp2 = l1.removeFirst();
                int tmp = tmp1+tmp2;
                ans+=tmp;
                if(l1.size()==0||tmp<=l1.getFirst()){
                    l1.addFirst(tmp);
                }
                else l2.add(tmp);
            }
            else if(l1.size()==0){
                int tmp1 = l2.removeFirst();
                int tmp2 = l2.removeFirst();
                int tmp = tmp1+tmp2;
                if(l2.size()==0||tmp<=l2.getFirst()){
                    l2.addFirst(tmp);
                }
                else l1.addFirst(tmp);
                ans+=tmp;
            }
            else{
                int tmp1 = l1.getFirst()<l2.getFirst()?l1.removeFirst():l2.removeFirst();
                int tmp2=0;
                if(l1.size()==0||l2.size()==0){
                    tmp2 = l1.size()==0?l2.removeFirst():l1.removeFirst();
                }
                else{
                    tmp2 = l1.getFirst()<l2.getFirst()?l1.removeFirst():l2.removeFirst();
                }
                int tmp = tmp1+tmp2;
                if(l1.size()==0||l1.getFirst()>=tmp){
                    l1.addFirst(tmp);
                }
                else l2.add(tmp);
                ans+=tmp;
            }
        }
        return ans;
    }
}
```