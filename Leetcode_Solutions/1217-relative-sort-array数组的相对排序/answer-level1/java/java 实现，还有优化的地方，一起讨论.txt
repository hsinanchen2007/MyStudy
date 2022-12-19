
```
public int[] relativeSortArrayBak(int[] arr1, int[] arr2) {
        //存储按照arr2排序的元素
        Stack<Integer> stack = new Stack<>();
        //存储arr2中没有的元素
        Map<Integer, Integer> map = new HashMap<>();
        //将arr2转成list
        List<Integer> list = Arrays.stream(arr2).boxed().collect(Collectors.toList());

        for (int ele : arr2) {
            for (int j = 0; j < arr1.length; j++) {
                if (ele == arr1[j]) {
                    //判断两种数组中相同的元素,并按照arr2的顺序
                    stack.push(arr1[j]);
                } else if (!list.contains(arr1[j]) && !map.containsKey(j)) {
                    //存储不同的元素
                    map.put(j, arr1[j]);
                }
            }
        }

        Object[] other = map.values().toArray();
        Arrays.sort(other);
        
        //拼装相同的元素
        for (int i = 0; i < arr1.length; i++) {
            if (i < stack.size()) {
                arr1[i] = stack.get(i);
            }
        }
        //拼装不同的元素
        for (int i = 0; i < other.length; i++) {
            arr1[stack.size()+i] = Integer.valueOf(other[i]+"");
        }

        return arr1;
    }
```
