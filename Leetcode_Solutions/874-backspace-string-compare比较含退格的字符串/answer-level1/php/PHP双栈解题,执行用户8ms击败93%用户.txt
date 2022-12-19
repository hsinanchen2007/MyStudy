双站操作
第一步 先将字符串做好入栈,但是碰到'#'则出栈
第二步 将剩下的栈内内容出栈判断
```
class Solution {

    /**
     * @param String $S
     * @param String $T
     * @return Boolean
     */
    function backspaceCompare($S, $T) {
        $count1 = strlen($S);
        $count2 = strlen($T);
        $sArr = $tArr = [];
        for ($i=0; $i<$count1; $i++) {
            if ($S[$i] == '#') {
                array_pop($sArr);
            } else {
                $sArr[] = $S[$i];
            }
        }
        for ($j=0; $j<$count2; $j++) {
            if ($T[$j] == '#') {
                array_pop($tArr);
            } else {
                $tArr[] = $T[$j];
            }
        }

        if (sizeof($sArr) == 0 && sizeof($tArr) == 0) {
            return true;
        }

        $countNum = sizeof($sArr) > sizeof($tArr) ? sizeof($sArr) : sizeof($tArr);
        for ($i=0; $i<$countNum; $i++) {
            $sTmp = array_pop($sArr);
            $tTmp = array_pop($tArr);
            if ($sTmp != $tTmp) {
                return false;
            }
        }
        return sizeof($sArr) == 0 && sizeof($tArr) == 0 ? true : false;
    }
}
```
