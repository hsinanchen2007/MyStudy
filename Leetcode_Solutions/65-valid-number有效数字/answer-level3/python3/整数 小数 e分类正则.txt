服了
.3  1.  40.e3  -.  2e0 等各种样例都有
```
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if s=="" or s=="." or s=='e':
            return False

        rezheng = re.compile("[-+]?[0-9]+$")
        redot = re.compile("[-+]?([0-9]+)\.[0-9]*$")
        redot2 = re.compile("[-+]?\.[0-9]+$")
        ree = re.compile("[-+]?([0-9]+|([-+]?([0-9]+)\.[0-9]*|[-+]?\.[0-9]+))e[-+]?[0-9][0-9]*$")

        # rec = re.compile("[+-]?[0-9]+(\.[0-9]+)?((e[-+]?[1-9][0-9]*))?$")
        if re.match(re.compile(rezheng),s):
            return True
        elif re.match(re.compile(redot),s) or re.match(re.compile(redot2),s):
            return True
        elif re.match(re.compile(ree),s):
            return True
        else:
            return False
```
