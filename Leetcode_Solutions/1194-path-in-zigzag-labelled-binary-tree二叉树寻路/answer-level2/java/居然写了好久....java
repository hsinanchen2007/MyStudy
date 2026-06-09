### 解题思路
此处撰写解题思路

### 代码

```java
    class Solution {
        public List<Integer> pathInZigZagTree(int label) {
            int level = 1;
            int levelCount = pow(level  - 1);
            int current = 1;
            int currentIndex = 0;
            int maxLevel = 1;
            for (int i = 1; i < 100; i++) {
                if (pow(i)-1 >= label ) {
                    maxLevel = i;
                    break;
                }
            }
            int [] array = new int[pow(maxLevel)];
            while (level <= maxLevel) {
                if (level % 2 == 1) {
                    for (int i = current; i < current + levelCount ; i++) {
                        array[currentIndex++] = i;
                    }
                }else if (level % 2 ==0 ) {
                    for (int i = current + levelCount -1; i >= current ; i--) {
                        array[currentIndex++] = i;
                    }
                }
                current = current + levelCount;
                level++;
                levelCount = pow(level  - 1);
            }
            List<Integer> ans = new ArrayList<>();
            currentIndex = findIndex(array,label);
            while (currentIndex != 0) {
                ans.add(array[currentIndex]);
                currentIndex = (currentIndex - 1) / 2 ;
            }
            ans.add(1);
            Collections.reverse(ans);
            return ans;
        }

        private int pow(int num) {
            int ans = 1;
            if (num != 0) {
                for (int i = 0; i < num; i++) {
                    ans *= 2;
                }
            }
            return ans;
        }

        private int findIndex(int[] array,int target) {
            for (int i = 0; i < array.length;i++) {
                if (array[i] == target) {
                    return i;
                }
            }
            return 0;
        }
    }
```