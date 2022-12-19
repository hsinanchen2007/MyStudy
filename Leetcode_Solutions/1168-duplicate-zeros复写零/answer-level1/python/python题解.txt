time: beat 91.82%, space: beat 100%

def f(arr):

    count = 0
    num_zero = 0

    for i in range(len(arr)):
        if arr[i] == 0:
            count += 2
            num_zero += 1
        else:
            count += 1
        if count >= len(arr):
            break
            
    k = len(arr) - 1
    no_dup_zero_num = num_zero - (len(arr) - 1 - i)
    
    while i >= 0:
        if no_dup_zero_num > 0:
            arr[k] = 0
            k -= 1
            no_dup_zero_num -= 1
        else:
            if arr[i] != 0:
                arr[k] = arr[i]
                k -= 1
            else:
                arr[k] = 0
                arr[k-1] = 0
                k -= 2
        i -= 1

找最后一位放入arr的index，backward的填充，注意最后多少个0是不需要duplicate的，对此做好判断就可以了