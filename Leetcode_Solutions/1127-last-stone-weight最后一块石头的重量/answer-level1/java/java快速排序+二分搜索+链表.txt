1. 使用快速排序将数组中的数字排序
2. 将数组中的数字放入一个链表中
3. 将链表中最后两个数字拿出来，做减法
4. 将减法得到的结果插入到顺序链表中，这个插入搜索使用的是二分查找
5. 重复上面步骤
6. ```
  public void quickSort(int[] stones,int left,int right){
        if(left < right){
            int p = part(stones,left,right);
            quickSort(stones,left,p-1);
            quickSort(stones,p+1,right);
        }
    }
    public int part(int[] stones,int left,int right){
        int i = left - 1;
        for (int j = left ; j <= right ; j++){

            if(stones[j] > stones[right]){
                i ++;
                int temp = stones[i];
                stones[i] = stones[j];
                stones[j] = temp;
            }
        }
        i++;
        int temp = stones[right];
        stones[right] = stones[i];
        stones[i] = temp;
        return i;
    }
    public void insertList(List<Integer> list,int r){
        int left = 0;
        int right = list.size() - 1;
        if(list.size() == 1){
            if (list.get(0)<r){
                list.add(r);
            }else {
                list.add(0,r);
            }
            return;
        }
        if(list.get(list.size()-1)<r){
            list.add(r);
            return;
        }
        while (left < right){
            int mid = (left + right)/2;
            if(list.get(mid) < r){
                left = mid + 1 ;
            }else if(list.get(mid) > r){
                right = mid ;
            }else{
                left = mid;
                break;
            }
        }

        list.add(left,r);

    }
    public int lastStoneWeight(int[] stones) {
        //1.    排序
        quickSort(stones,0,stones.length-1);
        //2.    变成链表
        List<Integer> list = new LinkedList<Integer>();
        for(int i : stones){
            list.add(0,i);
        }
        while (list.size() > 1){
            //3.    做差
            int r = list.get(list.size() - 1) - list.get(list.size() - 2);
            list.remove(list.size() - 1);
            list.remove(list.size() - 1);
            if (list.size() == 0){
                return r;
            }
            //4.    将差插入到链表中
            if (r != 0){
                insertList(list,r);
            }
        }
        if(list.size() == 0){
            return 0;
        }else{
            return list.get(0);
        }
    }

    public static void main(String[] args) {
        int[] stones = {3,7,2};
        int i = new _1046().lastStoneWeight(stones);
        System.out.println(i);
    }
```
