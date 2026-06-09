思路：
1、遍历两个String数组，将下标和对应值存入分别存入两个HashMap<String, Integer>中。初始化一个TreeMap。
2、判断两个数组长度的大小，分情况处理：
    一、数组一长度大于等于数组二：
        遍历数组二对应的HashMap，判断数组一对应的HashMap中是否存在该Key(餐厅名字)，若存在，将key(餐厅名字),下标之和添加入TreeMap；不存在则不处理。
    二、数组一长度小于等于数组二：
        遍历数组一对应的HashMap，判断数组二对应的HashMap中是否存在该Key(餐厅名字)，若存在，将key(餐厅名字),下标之和添加入TreeMap；不存在则不处理。
3、对得到的TreeMap做处理，由于要根据Value排序，因此先转化为一个ArrayList,调用Arrays.sort方法，重写Comparator接口，对value排序。（注：如果Key存储的是餐厅名对应的下标，则
利用TreeMap自己实现的Comparator接口便可排序，调用对应的ceilingKey方法即可，但是此处不适合将下标和作为Key,因为可能存在多个餐厅名的下标和相等）。

4、对排序后的ArrayList实例处理，若长度为0，返回NULL，若长度不为0，分情况处理：
    一：ArrayList长度为1，初始化一个String数组，实例为该ArrayList第一个元素。
    二：长度大于1，从下标为1的元素开始遍历ArrayList，判断是否ArrayList中所有元素的下标和是否和最小值相等，依次添加，最后初始化一个String数组将结果返回。

代码：
```
public static String[] findRestaurant(String[] list1, String[] list2) {
        if (list1.length == 0 || list2.length == 0) {
            return null;
        }

        TreeMap<String, Integer> resultMap = new TreeMap<String, Integer>();
        HashMap<String, Integer> map1 = new HashMap<String, Integer> ();
        HashMap<String, Integer> map2 = new HashMap<String, Integer> ();

        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }

        for (int i = 0; i < list2.length; i++) {
            map2.put(list2[i], i);
        }
        System.out.println(map1);
        System.out.println(map2);

        if (list1.length >= list2.length) {
            Set<Map.Entry<String, Integer>> set2 = map2.entrySet();
            for (Map.Entry<String, Integer> entry: set2) {
                if (map1.containsKey(entry.getKey())) {
                    resultMap.put(entry.getKey(), entry.getValue() + map1.get(entry.getKey()));
                }
            }
        } else if (list1.length <= list2.length) {
            Set<Map.Entry<String, Integer>> set1 = map1.entrySet();
            for (Map.Entry<String, Integer> entry: set1) {
                if (map2.containsKey(entry.getKey())) {
                    resultMap.put(entry.getKey(), entry.getValue() + map2.get(entry.getKey()));
                }
            }
        }

        List<Map.Entry<String, Integer>> entry = new ArrayList<Map.Entry<String, Integer>>(resultMap.entrySet());
        Collections.sort(entry, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        });
        System.out.println(entry);
        if (entry.size() != 0) {
            if (entry.size() > 1) {
                int times = entry.get(0).getValue();
                ArrayList<String> resultList = new ArrayList<>();
                resultList.add(entry.get(0).getKey());
                for (int i = 1; i < entry.size(); i++) {
                    if (times == entry.get(i).getValue()) {
                        resultList.add(entry.get(i).getKey());
                    } else {
                        break;
                    }
                }
                return resultList.toArray(new String[resultList.size()]);
            } else {
                String[] result = new String[]{entry.get(0).getKey()};
                return result;
            }
        }
        return null;
    }
```
