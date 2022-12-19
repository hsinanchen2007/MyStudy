### 解题思路
三次二分
避免查询次数过多使用自定义的缓存

### 代码

```java
/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {

        // 缓存
        MyMap cache = new MyMap(mountainArr);

        // 找出最大值
        int length = mountainArr.length();
        int maxV;
        int maxIndex;
        for (int l = 0, r = length; ; ) {
            int index = (l + r) / 2;


            int i = cache.get(index);
            int i1 = cache.get(Math.min(index + 1, length));
            int i2 = cache.get(Math.max(index - 1, 0));
            if (i > i1 && i > i2) {
                maxIndex = index;
                maxV = i;
                break;
            }
            if (i > i1) {
                r = index;
            } else {
                l = index;
            }
        }


        int i = find(0, maxIndex, target, cache, true);
        if (i > -1) {
            return i;
        } else {
            int i1 = find(maxIndex, length, target, cache, false);
            if (i1 > -1) {
                return i1;
            }
            return -1;
        }


    }

    private int find(int l, int r, int target, MyMap myMap, boolean asc) {
        for (int index = (l + r) / 2; ; index = (l + r) / 2) {
            System.out.print(l);
            System.out.print(":" + r);
            System.out.println(":" + index);
            if (l >= r-1) {
                if (myMap.get(l).equals(target)) {
                    System.out.println("find:" + l);
                    return l;
                } else {
                    return -1;
                }
            }

            if (target > myMap.get(index)) {
                if (asc) {
                    l = index;
                } else {
                    r = index;
                }
            } else if (target < myMap.get(index)) {
                if (asc) {
                    r = index;
                } else {
                    l = index;
                }
            } else {
                System.out.println("return:" + index);
                return index;
            }
        }
    }

    // cache
    public static class MyMap extends HashMap<Integer, Integer> {
        private MountainArray mountainArray;
        private int lengthMax;
        public int mz = 0;
        public int jc = 0;

        public MyMap(MountainArray mountainArray) {
            super();
            this.mountainArray = mountainArray;
            this.lengthMax = mountainArray.length();
        }


        @Override
        public Integer get(Object index) {
            if ((Integer) index > lengthMax || (Integer) index < 0) {
                return Integer.MIN_VALUE;
            }
            Integer e = super.get(index);
            if (null == e) {
                jc++;
                int i = mountainArray.get(((Integer) index));
                super.put((Integer) index, i);
                return i;
            } else {
                mz++;
            }

            return e;
        }
    }



}
```