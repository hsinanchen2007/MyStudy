![image.png](https://pic.leetcode-cn.com/fe4107936cd60e0fbf36afa397c08c28b3bf328d224ed325cf33e669249676af-image.png)

#判断是否为素数
    def judge_prime(self, num):
        if num < 2:
            return False
        import math
        end = int(math.sqrt(num))
        for i in range(2,end+1):
            if num % i == 0:
                return False
        return True
    def judge_Palindrome(self, num):
        tmp = []
        while num > 0:
            tmp.append(num%10)
            num = num // 10
        if tmp == tmp[::-1]:
            return True
        else:
            return False
    def primePalindrome(self, N: int) -> int:
        import math
        num = N
        flag = 0
        add_list = [1,1,10,100,1000,10000,100000]
        while True:
            if flag == 0:
                if self.judge_Palindrome(num):
                    flag = 1 #表示已经找到第一个回文数了
                    if self.judge_prime(num):
                        return num
                    else:
                        continue
                else:
                    num += 1
            else:
                #生成下一个回文数
                tmp = str(num)
                L = len(tmp)
                index = L // 2
                index += 1
                if L % 2 == 1:
                    if tmp[math.floor(L / 2)] == "9":
                        count = 0
                        for i in range(math.floor(L / 2),-1,-1):
                            if tmp[i] == "9":
                                count += 1
                            else:
                                break
                        if count == index:
                            num += 2
                        else:
                            num += (add_list[index] + add_list[index-1]) // pow(10,count-1)
                    else:
                        num += add_list[index]
                else:
                    if tmp[math.floor(L / 2)] == "9":
                        count = 0
                        for i in range(math.floor(L / 2),-1,-1):
                            if tmp[i] == "9":
                                count += 1
                            else:
                                break
                        if count == index:
                            num += 2
                        else:
                            num += (add_list[index] + add_list[index-1]) // pow(10,count-1)
                    else:
                        num += add_list[index] + add_list[index-1]

                #判断是否是素数
                if self.judge_prime(num):
                    return num