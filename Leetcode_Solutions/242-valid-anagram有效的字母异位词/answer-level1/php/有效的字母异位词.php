刚看这题目，想到对字符串进行字符间排序，按ASCII升序处理后，两个字符串进行比对即可。
初步用较为耗时的选择排序，结果耗时。
再使用快速排序，仍然超时？（PHP实现），看了下题解也是相同的思路，检查了快排代码也无问题，暂不纠结，思路到位。

后面用数组求解，两种思路
<br />1、将小写字母处理成0~26的整型值
<br />2、将单个字母作为哈希键名存储

解法1更快速，解法2更全面通用，可惜mb系列的函数不支持。

解法1：

    class Solution {

        /**
        * @param String $s
        * @param String $t
        * @return Boolean
        */
        function isAnagram($s, $t) {
            if (strlen($s) != strlen($t)) {
                return false;
            }

            $nums1 = [];
            $nums2 = [];
            for ($i=0; $i<26; $i++) {
                $nums1[$i] = 0;
                $nums2[$i] = 0;
            }

            $length = strlen($s);
            for ($i=0; $i<$length; $i++) {
                $nums1[ord($s[$i]) - 97]++;
                $nums2[ord($t[$i]) - 97]++;
            }

            for ($i=0; $i<26; $i++) {
                if ($nums1[$i] != $nums2[$i]) {
                    return false;
                }
            }
            return true;
        }
    }

解法2：

    class Solution {

        /**
        * @param String $s
        * @param String $t
        * @return Boolean
        */
        function isAnagram($s, $t) {
            if (strlen($s) != strlen($t)) {
                return false;
            }

            $hash1 = [];
            $hash2 = [];
            $length = strlen($s);
            for ($i=0; $i<$length; $i++) {
                $hash1[$s[$i]] = empty($hash1[$s[$i]]) ? 1 : $hash1[$s[$i]]+1;
                $hash2[$t[$i]] = empty($hash2[$t[$i]]) ? 1 : $hash2[$t[$i]]+1;
            }
            foreach ($hash1 as $char => $num) {
                if (empty($hash2[$char]) || $hash2[$char] != $num) {
                    return false;
                }
            }
            return true;
        }
    }
