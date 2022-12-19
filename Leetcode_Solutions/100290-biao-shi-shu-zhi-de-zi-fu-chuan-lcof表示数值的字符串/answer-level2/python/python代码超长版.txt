### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        if not s:
            return False
        if len(s) == 1 and (s[0] == 'e' or s[0] == 'E' or s[0] == '.'):
            return False
        if '.' in s:
            index_ = s.index('.')
            int_ = s[:index_] #整数部分
            float_e = s[index_+1:] #小数部分 或者 小数部分和(E/e)的部分
            print('int_=',int_)
            print('float_e=',float_e)
            
            if ('e' in float_e) and  ('E' in float_e):
                return False
            elif 'e' in float_e:
                index_e = float_e.index('e')
                print(index_e)
                float_ = float_e[:index_e]
                e_ = float_e[index_e+1:]
                print('float_=',float_)
                print('e_=',e_)
                if not int_ and not float_:
                    return False
                elif not int_:
                    return self.isFloat(float_) and self.isE(e_)
                elif not float_:
                    return self.isInt(1, int_) and self.isE(e_)
                else:
                    return (self.isInt(1, int_) and self.isFloat(float_) and self.isE(e_)) or \
                           (self.isInt(0, int_) and self.isFloat(float_) and self.isE(e_))
            elif 'E' in float_e:
                index_e = float_e.index('E')
                float_ = float_e[:index_e]
                e_ = float_e[index_e+1:]
                if not int_ and not float_:
                    return False
                elif not int_:
                    return self.isFloat(float_) and self.isE(e_)
                elif not float_:
                    return self.isInt(1, int_) and self.isE(e_)
                else:
                    return (self.isInt(1, int_) and self.isFloat(float_) and self.isE(e_)) or \
                           (self.isInt(0, int_) and self.isFloat(float_) and self.isE(e_))
            else:
                if not int_ and not float_e:
                    return False
                elif not int_:
                    return self.isFloat(float_e)
                elif not float_e:
                    return self.isInt(1,int_)
                else:
                    return (self.isInt(1, int_) and self.isFloat(float_e)) or (self.isInt(0, int_) and self.isFloat(float_e))
          
        else:
            #不存在小数部分 接下来看下是否存在e/E的部分
            if ('e' in s) and  ('E' in s):
                return False
            elif 'e' in s:
                index_e = s.index('e')
                int_ = s[:index_e]
                e_ = s[index_e+1:]
                if not int_ or not e_:
                    return False
                else:
                    return self.isInt(1,int_) and self.isE(e_)
            elif 'E' in s:
                index_e = s.index('E')
                int_ = s[:index_e]
                e_ = s[index_e+1:]
                if not int_ or not e_:
                    return False
                else:
                    return self.isInt(1,int_) and self.isE(e_)                
            else:
                #不存在含有e/E的部分 直接判断整数部分
                return self.isInt(1,s)

    def isInt(self, hasNumber, int_):
        print('int__= ',int_)
        if int_[0] == '+' or int_[0] == '-':
            int_ = int_[1:]
        if hasNumber:
            print('efe')
            print(int_)
            if not int_:
                return False
            else:
                for i in range(len(int_)):
                    print(int_[i])
                    if int_[i] >= '0' and int_[i] <= '9':
                        continue
                    else:
                        print('ddd')
                        return False
        else:
            for i in range(len(int_)):
                if int_[i] >= '0' and int_[i] <= '9':
                    continue
                else:
                    return False           
        return True                


        

    def isFloat(self, float_):
        for i in range(len(float_)):
            if float_[i] >= '0' and float_[i] <= '9':
                continue
            else:
                return False
                
        return True
    def isE(self, e_):
        print('e_=',e_)
        if not e_:
            return False
        if e_[0] == '+' or e_[0] == '-':
            e_ = e_[1:]
            if not e_:
                return False
            for i in range(len(e_)):
                if e_[i] >= '0' and e_[i] <= '9':
                    continue
                else:
                    return False

        elif not e_ :
            return True
        else:
            for i in range(len(e_)):
                if e_[i] >= '0' and e_[i] <= '9':
                    continue
                else:
                    return False
    
        return True        
         
```