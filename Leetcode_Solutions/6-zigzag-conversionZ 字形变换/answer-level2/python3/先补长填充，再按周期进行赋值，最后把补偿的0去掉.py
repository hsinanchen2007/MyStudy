class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s:
            return ""
        if numRows == 1:
            return s
        index = 0
        period = int((numRows - 1) * 2)
        if len(s)%period != 0:
            str1 = " " * int(period - len(s)%period)
            s = s + str1
        arr = [0] * (len(s))
        print(len(arr))
        for i in range(int(len(s)/period)):
            arr[index] = s[i*period]
            index += 1
        for j in range(1,numRows-1):
            for i in range(int(len(s)/period)):
                arr[index] = s[i*period+j]
                index += 1
                arr[index] = s[(i+1)*period-j]
                index += 1
        for i in range(int(len(s)/period)):
            arr[index] = s[i*period+numRows-1]
            index += 1
        return ''.join(arr).replace(" ","")