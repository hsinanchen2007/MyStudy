先求得列表中任意2个数之和，存入一个新的列表L2中，然后在L2找出两数相加等于target的所有非重复组合，再进一步进行分解
此方法较为笨拙，但还算是比较适合初学者吧
class Solution:

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        L1 = sorted(nums)
        # print('L1 = ', end='')
        # print(L1)
        L2 = []
        for i in range(len(L1)):
            for j in L1[i+1:]:
                L2.append(int(L1[i]+j))
        # 求出nums中任意两数相加之和的列表
        # 将四数之和转化为两数之和
        # print('L2 = ', end='')
        # print(L2)
        # 求两数之和
        two_sum = []
        hashmap = {}
        for ind,num in enumerate(L2):
            hashmap[num] = ind
        for i,num in enumerate(L2):
            j = hashmap.get(target - num)
            if j is not None and i!=j:
                add_num = sorted([L2[i],L2[j]])
                if add_num not in two_sum:
                    two_sum.append(add_num)
        # print('two_sum = ', end='')
        # print(two_sum)
        # 求出两数组合two_sum
        L_out = []
        for i in two_sum:
            target_list = i
             #print('target_list = ', end='')
             #print(target_list)
            hashmap_L = {}
            hashmap_R = {}
            destination_L = []
            destination_R = []
            for ind,num in enumerate(L1):
                hashmap_L[num] = ind
                hashmap_R[num] = ind
                #print('hashmap_L = ', end='')
                #print(hashmap_L)
                #print('hashmap_R = ', end='')
                #print(hashmap_R)
            
            for r,num in enumerate(L1):
                 #print(target_list[0] - num)
                j = hashmap_L.get(target_list[0] - num)
                k = hashmap_R.get(target_list[1] - num)
                if j is not None and r!=j:
                    add_num_L = sorted([L1[r],L1[j]])
                    if add_num_L not in destination_L:
                        destination_L.append(add_num_L)
                if k is not None and r!=k:
                    add_num_R = sorted([L1[r],L1[k]])
                    if add_num_R not in destination_R:
                        destination_R.append(add_num_R)
             #print('destination_L = ', end='')
             #print(destination_L)
             #print('destination_R = ', end='')
             #print(destination_R)
            for p in destination_L:
                for q in destination_R:
                    insert = sorted(p + q)
                    if insert not in L_out:
                        L_out.append(insert)
            
        # 得到的L_out中会存在不符合要求的组合，需要进行筛选
          #print('L_out = ', end='')
          #print(L_out)
        x = 0
        lens = len(L_out)
        while x < lens:
            L_temp = sorted(nums)
              #print(L_temp)
              #print(L_out[x])
            flag = 0
            for i in range(len(L_out[x])):
                if L_out[x][i] in L_temp:
                    #print('ok')
                    del L_temp[L_temp.index(L_out[x][i])]
                else:
                    #print('problem')
                    del L_out[x]
                    flag = 1
                    break
            if flag == 0:
                x += 1
            else:
                lens += -1
        return L_out