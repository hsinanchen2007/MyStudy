执行用时 :23 ms, 在所有 java 提交中击败了100.00%的用户内存消耗 :43.9 MB, 在所有 java 提交中击败了100.00%的用户

题目考点就是维护最大值表,而最大值表是有序的,在这里用二分比较快.

(本来用了2个linkedlist,效率感人.换成了arraylist直接第一了.)

```
class MaxStack {
  ArrayList<Integer> linkedStacks=new ArrayList<>();
    ArrayList<Integer> maxStacks=new ArrayList<>();
    public void push(int x) {
        linkedStacks.add(x);
        if(maxStacks.size()==0){
            maxStacks.add(x);
        }else {
            if (x >= maxStacks.get(maxStacks.size()-1))
                maxStacks.add(x);
            else if (x < maxStacks.get(0)) {
                maxStacks.add(0, x);
            }else {
                int maxIndex = binarySearch(maxStacks, x, 0, maxStacks.size());
                maxStacks.add(maxIndex, x);
            }
        }
    }
    public int binarySearch(ArrayList<Integer> list,int num,int lo,int hi){
        if(lo>hi)
            return -1;
        int mid=(lo+hi)/2;
        if (list.get(mid)<=num){
            int i=1;
            while (mid+i<list.size()&&list.get(mid+i)<=num)
                ++i;
            if(mid+i<list.size()&&list.get(mid+i)>num)
                return mid+i;
            else
                return binarySearch(list,num,mid+1,hi);
        } else
            return binarySearch(list,num,lo,mid-1);
    }
    public int pop() {
        if(maxStacks.get(maxStacks.size()-1).equals(linkedStacks.get(linkedStacks.size()-1)))
            maxStacks.remove(maxStacks.size()-1);
        else {
            int t = binarySearch(maxStacks, linkedStacks.get(linkedStacks.size()-1), 0, maxStacks.size());
            maxStacks.remove(t-1);
        }
        return linkedStacks.remove(linkedStacks.size()-1);
    }
    public int top() {
        return linkedStacks.get(linkedStacks.size()-1);
    }
    public int peekMax() {
        return maxStacks.get(maxStacks.size()-1);
    }
    public int popMax() {
        for(int i=linkedStacks.size()-1;i>=0;--i){
            if(linkedStacks.get(i).equals(maxStacks.get(maxStacks.size()-1))) {
                linkedStacks.remove(i);
                break;
            }
        }
        return maxStacks.remove(maxStacks.size()-1);
    }
}

```
