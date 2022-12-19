### 解题思路
此处撰写解题思路
方法有点笨，循环添加
### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $length = strlen($s);
		if ($length <= 1) return $length;
		if ($length > 40000) return 0;

		$strList = str_split($s);
		$tempMap = [];
		$noRepeatCharList = [];
		foreach ($strList as $k => $v) {
			if (!isset($tempMap[$k])) {
				$tempMap[$k] = [];
			}
			foreach ($tempMap as $key => $value) {
				if (!in_array($v, $value)) {
					$tempMap[$key][] = $v;
				} else {
					$noRepeatCharList[] = $value;
					unset($tempMap[$key]);
				}
			}

		}

		$lastNoRepeatCharList = array_merge($noRepeatCharList, $tempMap);
		$maxLength = 0;
		//$maxLengthChar = '';
		foreach ($lastNoRepeatCharList as $val) {
			if (count($val) > $maxLength) {
				$maxLength = count($val);
				$maxLengthChar = implode('', $val);
			}
		}

		//var_dump($maxLengthChar);
		return $maxLength;
    }
}
```