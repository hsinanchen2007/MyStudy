    public int[] relativeSortArray(int[] arr1, int[] arr2) {
     //将arr1中存在于arr2中的重复元素添加到arr2中，
        //将arr1中不存在于arr2中的元素按照升序排序，再将两个结果集合并
        List<Integer> list1 = Arrays.stream(arr1).boxed().collect(Collectors.toList());
        List<Integer> list2 = Arrays.stream(arr2).boxed().collect(Collectors.toList());
        List<Integer> list3 = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < list1.size(); i++) {
            if (list2.contains(list1.get(i))) {
                //说明此时这个数据在list2中存在
                if (!map.containsKey(list1.get(i))) {
                    map.put(list1.get(i), 1);
                } else {
                    map.put(list1.get(i), map.get(list1.get(i)) + 1);
                }
            } else {
                //可以把不存在的元素也先临时缓存起来
                list3.add(list1.get(i));
            }
        }

        //组装临时list,先缓存在arr1里面的元素
        List<Integer> templist = new ArrayList<>();
        //将list转为set
        for (Integer integer : list2) {
            if (templist.contains(integer)) {
                continue;
            }
            if (map != null && map.size() > 0) {
                if (map.containsKey(integer)) {
                    for (int i = 0; i < map.get(integer); i++) {
                        templist.add(integer);
                    }
                }
            }
        }
       int[] ints = list3.stream().mapToInt(Integer::intValue).toArray();
        //参数直接用list转array,结果没有变
         Arrays.sort(ints);
        list3= Arrays.stream(ints).boxed().collect(Collectors.toList());
        templist.addAll(list3);
        arr1 = templist.stream().mapToInt(Integer::valueOf).toArray();
        return arr1;
    }