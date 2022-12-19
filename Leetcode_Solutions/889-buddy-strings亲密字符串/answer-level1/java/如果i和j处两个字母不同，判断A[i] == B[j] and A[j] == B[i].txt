```
class Solution {
        /**https://www.cnblogs.com/xiaochuan94/p/10842445.html
         * 三种情况：
         * 1.A和B的长度不相等。两者的长度不相等，无论A怎么换字母，都不可能变成B，直接返回false。

         2. A和B的长度相等，并且A和B相等。要想满足A换两字母后能够等于B，A就必须至少要有一个字母出现两次以上，
         因为只有交换重复出现的字母，A才不会变，也就可以和B相等了。
         例如，A="aa"，B="aa"，或者A="afag"，B="afag"，这两组都是满足条件。
         再例如，A="abc"，B="abc"，虽然A等于B，但是A无论交换哪两个字母，交换后的新A都不会等于B。

         3. A和B的长度相等，但是A和B不相等。同样，要想A交换两个字母后等于B，
         前提条件就是在对应索引位置上A不等于B的字母的个数，只能是2个，多于2个或少于2个都不行。
         同时还要满足：A中第一个不等于B的字母要等于B中不等于A的第二个字母，A中第二个不等于B的字母要等于B中不等于A的第一个字母。
         换成伪代码就是A[i] == B[j] and A[j] == B[i]，i和j是A和B两个不同字母的索引。
         *
         在第二种情况中，使用一个长度为26的整数数组，来判断A中是否有重复出现的字母。

         在第三种情况中，使用两个临时变量存储A和B中对应位置字母不相等的索引值，如果字母不相等的个数多于2个就直接返回false，最后判断两个索引位置上对应的字母是否交叉相等。

         此解法的时间复杂度是O(N)，空间复杂度是O(1)。
         * @param A
         * @param B
         * @return
         */
        public boolean buddyStrings4(String A, String B) {
            if (A.length() != B.length()) {
                return false;
            }
            if (A.equals(B)) {
                int[] arr = new int[26];
                for (char ch : A.toCharArray()) {
                    if (++arr[ch-'a'] >= 2) {
                        return true;
                    }
                }
                return false;
            } else {
                int index = -1;
                int index2 = -1;
                int n = A.length();
                for (int i=0; i<n; i++) {
                    if (A.charAt(i) != B.charAt(i)) {
                        if (index == -1) {
                            index = i;
                        } else if (index2 == -1) {
                            index2 = i;
                        } else {
                            return false;
                        }
                    }
                }
                return A.charAt(index) == B.charAt(index2) &&
                        A.charAt(index2) == B.charAt(index);
            }
        }
    }
```
