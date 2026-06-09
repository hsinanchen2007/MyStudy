        m,n = len(num1),len(num2)
        carry = 1
        count = 0
        ans = 0
        for i in range(m-1,-1,-1):
            count += 1
            carry = 10**(count-1)
            for j in range(n-1,-1,-1):
                ans += int(num1[i]) * int(num2[j]) * carry
                carry *= 10
        return str(ans)