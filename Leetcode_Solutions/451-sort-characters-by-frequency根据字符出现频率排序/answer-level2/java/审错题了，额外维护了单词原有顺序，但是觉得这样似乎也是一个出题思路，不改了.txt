### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        if (null == s || s.trim().length() == 0) {
            return s;
        }
        char[] chars = s.toCharArray();
        List<MyPair<Character, Integer>> list = new ArrayList<>(chars.length);

        for (int i = 0; i < chars.length; i++) {
            char c = chars[i];
            MyPair<Character, Integer> myPair = new MyPair<>(c, 1);
            if (list.contains(myPair)) {
                int index = list.indexOf(myPair);
                myPair = list.get(index);
                myPair.value = myPair.value + 1;
                list.set(index, myPair);
            } else {
                list.add(myPair);
            }
        }
        list.sort((p1, p2) -> p2.value - p1.value);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            MyPair<Character, Integer> pair = list.get(i);
            for (int j = 0; j < pair.value; j++) {
                sb.append(pair.key);
            }
        }
        return sb.toString();
    }

    private class MyPair<K, V> {
        K key;
        V value;

        public MyPair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public int hashCode() {
            return key.hashCode() * 13;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o instanceof MyPair) {
                MyPair pair = (MyPair) o;
                if (key != null ? !key.equals(pair.key) : pair.key != null) {
                    return false;
                }
                return true;
            }
            return false;
        }
    }
}
```