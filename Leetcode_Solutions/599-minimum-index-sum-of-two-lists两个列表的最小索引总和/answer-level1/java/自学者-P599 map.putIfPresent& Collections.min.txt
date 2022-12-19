### 解题思路
* 使用一下JDK8的新接口存储
* 使用Collection.min快速反馈key数值

### 代码

```java
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        assert list1.length >=1 && list2.length>=1;
        assert list1.length <=1000 && list2.length <= 1000;
        List<String> ans = new ArrayList<>();
        Map<Integer,List<String>> indexRests = new HashMap<>();
        for(int i = 0; i < list1.length; i++) {
            for(int j = 0; j < list2.length; j++) {
                if(list1[i].equals(list2[j])) {
                    List<String> rest = indexRests.putIfAbsent(i+j,new ArrayList<>());
                    if (null == rest) {
                        rest = indexRests.get(i+j);
                    }
                    rest.add(list1[i]);
                    break;
                }
            }
        }
        Integer minKey = Collections.min(indexRests.keySet());
        ans = indexRests.get(minKey);
        String[] result = new String[ans.size()];
        ans.toArray(result);
        return result;
    }
}
```