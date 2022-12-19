我觉得官方解题的第一个方法超好理解，但是在我的环境上报错。重新用这个思想实现了一次。和官方代码有区别。已通过。

```
public  List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list=new ArrayList<>();
        for (int i = 0; i <arr.length ; i++) {
            list.add(arr[i]);
        }
        Collections.sort(list,new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Math.abs(o1-x)-Math.abs(o2-x);
            }
        });

         list=list.subList(0,k);
        Collections.sort(list);
        return list;
    }
```
