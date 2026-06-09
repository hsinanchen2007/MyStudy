遍历字符串，使用StringBuilder拼接新的字符串，循环中碰到'.'就放弃原来的'.'，然后把自己的'[','.',']'拼接上去，麻麻再也不用担心我的效率不够快啦，哦耶！
```
        public string DefangIPaddr (string address) {
            StringBuilder newStr = new StringBuilder ();
            for (int i = 0; i < address.Length; i++) {
                if (address[i] != '.') {
                    newStr.Append (address[i]);
                } else {
                    newStr.Append ('[');
                    newStr.Append ('.');
                    newStr.Append (']');
                }
            }

            return newStr.ToString ();
        }
```
