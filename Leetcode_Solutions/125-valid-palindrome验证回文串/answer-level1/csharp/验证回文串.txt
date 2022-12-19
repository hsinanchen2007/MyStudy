**思路1：** 双指针，从字符串两头往中间遍历并进行比对，跳过非数字或字母项。
```
public bool IsPalindrome(string s)
        {
            if (s == null)
            {
                return false;
            }

            int left = 0;
            int right = s.Length - 1;
            while (left <= right)
            {
                var leftElement = char.ToLower(s[left]);
                var rightElement = char.ToLower(s[right]);
                if ((leftElement >= 'a' && leftElement <= 'z' || leftElement >= '0' && leftElement <= '9') && rightElement >= 'a' && rightElement <= 'z' || rightElement >= '0' && rightElement <= '9')
                {
                    if (leftElement != rightElement)
                    {
                        return false;
                    }
                    left++;
                    right--;
                }
                else if (leftElement >= 'a' && leftElement <= 'z' || leftElement >= '0' && leftElement <= '9')
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }

            return true;
        }
```
利用现成类库进一步简化代码
```
public bool IsPalindrome(string s)
        {
            if (s == null)
            {
                return false;
            }

            int left = 0;
            int right = s.Length - 1;
            while (left <= right)
            {
                var leftElement = s[left];
                var rightElement = s[right];
                //case1: 左右指针指向的都是字母或字符串
                if (char.IsLetterOrDigit(leftElement) && char.IsLetterOrDigit(rightElement))
                {
                    if (char.ToLower(leftElement) != char.ToLower(rightElement))
                    {
                        return false;
                    }
                    left++;
                    right--;
                }
                //case2: 左指针指向的是字母或字符串
                else if (char.IsLetterOrDigit(leftElement))
                {
                    right--;
                }
                //case3: 右指针指向的是字母或字符串
                else
                {
                    left++;
                }
            }

            return true;
        }
```
