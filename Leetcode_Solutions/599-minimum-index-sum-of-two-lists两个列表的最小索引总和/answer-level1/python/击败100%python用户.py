class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        hash1={}
        hash2={}
        key_list=[]
        value_sum_list=[]
        return_list=[]
        for n,i in enumerate(list1):
            hash1[i]=n

        for m,j in enumerate(list2):
            if j in hash1:
                key_list.append(j)
                hash2[j]=m

        if len(key_list)==1:
            return key_list
        
        for k in key_list:
            value_sum_list.append(hash1[k]+hash2[k])

        min_sum=min(value_sum_list)

        for i in range(len(value_sum_list)):
            if value_sum_list[i]==min_sum:
                return_list.append(key_list[i])
        return return_list