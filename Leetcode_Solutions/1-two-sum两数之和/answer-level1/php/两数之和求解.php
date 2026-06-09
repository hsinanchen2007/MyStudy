首先，发现有个坏习惯，代码简单调试通过后，没仔细检查就选择提交，结果老是犯一些错误，不是个好习惯。

初步想法是元素只要比target小，就把差值和对应的下标存储下来。
<br />这里有思维偏差和调试时的问题。
<br />1、想着可以节省点数据，每次元素比target小才计算差值，没考虑到负数的情况，比如数组内存在-1,-2，而target为-3，此时两元素都比target大，但是仍然是要计算差值的。所以将元素和target判断大小不可取。
<br />2、PHP的数组内，键不可重复，所以刚开始觉得踏入了死循环，比如数组内3,3，映射数组内首先存储3=>0，会覆盖存储3=>1，把我给整晕了，误以为无法求解。

先用暴力循环求解的方式试了下：外部循环到一个元素时，循环判断是否存在后续元素与当前元素相加等于target。

    class Solution {

        /**
        * @param Integer[] $nums
        * @param Integer $target
        * @return Integer[]
        */
        function twoSum($nums, $target) {
            $length = count($nums);
            for ($i=0; $i<$length; $i++) {
                $tmp = $target - $nums[$i];
                for ($j=$i+1; $j<$length; $j++) {
                    if ($nums[$j] == $tmp) {
                        return [$i, $j];
                    }
                }
            }
            return [];
        }
    }

后来知道有哈希表的求解方法，分析了映射数组的生成过程。
<br />比如：
<br />数组内3,3，target=6，最终存储的是3=>1；
<br />数组内2,4,5，target=7，最终存储5=>0,3=>1,2=>2。

我们将数组从0开始重新循环，此时第一个数组下标为0的3就能满足条件；第二个数组下标为0时，即可得出答案。
<br />也就是说我们不需要考虑出现重复键，重复情况下，如果和target值有关，因为是从数组的0处开始循环，一定会找到下标不一致的相同元素，如3,3。

应用到哈希表的解法代码：要注意映射数组内的元素下标不可与当前下标相同。若不加判断，数组3,3，会返回[0,0]。

    class Solution {

        /**
        * @param Integer[] $nums
        * @param Integer $target
        * @return Integer[]
        */
        function twoSum($nums, $target) {
            $length = count($nums);
            $data = [];
            for ($i=0; $i<$length; $i++) {
                $data[$target - $nums[$i]] = $i;
            }

            for ($i=0; $i<$length; $i++) {
                if (isset($data[$nums[$i]]) && $data[$nums[$i]] != $i) {
                    return [$i, $data[$nums[$i]]];
                }
            }
            return [];
        }
    }

再来看一个例子：3,2,5,0 target=8
映射数组生成的顺序如下：
<br />1、5=>0
<br />2、5=>0,6=>1
循环到元素5时，发现已存在另一半解，获取到对应下标0和当前下标2，可立即得出解，不需要进行两次length的循环。

过程中又是一个思考不仔细之处，比如3,3，处理的时候每次先存储到映射数组内，导致先覆盖存储了3=>1，然后由于当前坐标为1，导致未得出解。<br />
回到上面的例子，元素5的差值3不用往映射数组内添加，先判断元素5是否已在映射数组内存在，若存在直接输出，不存在再进行添加。

    class Solution {

        /**
        * @param Integer[] $nums
        * @param Integer $target
        * @return Integer[]
        */
        function twoSum($nums, $target) {
            $length = count($nums);
            $data = [];
            for ($i=0; $i<$length; $i++) {
                if (isset($data[$nums[$i]])) {
                    return [$data[$nums[$i]], $i];
                }
                
                $data[$target - $nums[$i]] = $i;
            }
            return [];
        }
    }