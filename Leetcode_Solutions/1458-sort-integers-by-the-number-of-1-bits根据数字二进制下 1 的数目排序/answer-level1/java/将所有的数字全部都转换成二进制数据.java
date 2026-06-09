### 解题思路
此处撰写解题思路
将所有的数字全部都转换成二进制数据，补起位数，进行第一次排序。此时是按照1的个数来排序，为有序。
但1相同的数据，此时十进制又不一定有序，此时需要将这一部分数据转成十进制再次排序。
两次之后即可满足先是二进制，再是十进制排序

### 代码

```java
class Solution {
    public int[] sortByBits(int[] arr) {
 HashMap<String, ArrayList<Integer>> hashMap = new HashMap<>();
        ArrayList<String> list = new ArrayList<>();
        int max = arr[getMaxIndex(arr)];
        String binary = Integer.toBinaryString(max);
        for (int i= 0;i<arr.length;i++){
            String obj = Integer.toBinaryString(arr[i]);
            int dis = binary.length()- obj.length();
            for (int j=0;j<=dis;j++){
               obj =  "0".concat(obj);
            }
            list.add(obj);
        }
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return getOneCount(o1)-getOneCount(o2);
            }
        });
        for (int i =0;i<list.size();i++){
            String key = getOneCount(list.get(i))+"";
            ArrayList<Integer> os=  hashMap.get(key);
            if (os==null) os = new ArrayList<>();
            os.add(Integer.parseInt(list.get(i),2));
            hashMap.put(getOneCount(list.get(i))+"",os);
        }
        for (Map.Entry<String, ArrayList<Integer>> entry : hashMap.entrySet()) {
            Collections.sort(entry.getValue());
        }
       ArrayList<Integer> strings = new ArrayList<>();
        for (int i=0;i<max;i++){
            if (hashMap.get(i+"")!=null){
                strings.addAll(hashMap.get(i+""));
            }
        }
        int[] res = new int[strings.size()];
        for (int i =0;i<strings.size();i++){
            String key = strings.get(i)+"";
           int  re = Integer.parseInt(key,10);
           res[i] = re;
        }
        return res;
    }

    private static int getOneCount(String binary){
        return binary.replace("0","").length();
    }
    private static int getMaxIndex(int[] arr){
        int maxIndex = 0;
        for (int i=0;i<arr.length;i++){
            if (arr[i]>arr[maxIndex]){
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}
```