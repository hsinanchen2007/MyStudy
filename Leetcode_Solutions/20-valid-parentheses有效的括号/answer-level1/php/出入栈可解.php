### 解题思路
先入栈后出栈

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $s = trim($s);
		$length = strlen($s);
		if ($length <= 0) return true;

		$tempList = [];
		for ($i = 0; $i < $length; $i++) {
			if (in_array($s[$i], ['(', '[', '{'])) {
				array_push($tempList, $s[$i]);
			}

			if (in_array($s[$i], [')', ']', '}'])) {
				$lastTempChar = array_pop($tempList);
				if (!$lastTempChar) {
					return false;
				}
				switch ($s[$i]) {
					case ')':
						if ($lastTempChar != '(') {
							return false;
						}
						break;
					case ']':
						if ($lastTempChar != '[') {
							return false;
						}
						break;
					case '}':
						if ($lastTempChar != '{') {
							return false;
						}
						break;
					default:
						break;
				}

			}
		}
        if (!empty($tempList)) {
			return false;
		}

		return true;
    }
}
```