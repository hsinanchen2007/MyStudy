class ListNode(object):
    
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.data = dict() #key:[node, freq]
        self.freq = dict() #freq:[head, tail, nums]
        self.minfreq = float('inf')
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.data:
            return -1
        self.updatefreq(key)
        return self.data[key][0].value
    
    def updatefreq(self, key):
        #删除未增加1的频率对应下链表中的节点，在新的+1频次下的链表末尾加入新值
        if self.freq[self.data[key][1]][2] == 1:
            if self.minfreq == self.data[key][1]: 
                self.minfreq += 1
            self.freq.pop(self.data[key][1])
        else:
            self.freq[self.data[key][1]][2] -= 1
            m = self.data[key][0].prev
            m.next = m.next.next
            m.next.prev = m
        new_freq = self.data[key][1] + 1
        if new_freq not in self.freq:
            #创建新的freq
            self.freq[new_freq] = [ListNode(), ListNode(), 1]
            self.freq[new_freq][0].next = self.data[key][0]
            self.data[key][0].prev = self.freq[new_freq][0]
            self.freq[new_freq][1].prev = self.data[key][0]
            self.data[key][0].next = self.freq[new_freq][1]
        else:
            #插入到该频率节点的末尾
            m = self.freq[new_freq][1].prev
            m.next = self.data[key][0]
            self.data[key][0].prev = m
            self.data[key][0].next = self.freq[new_freq][1]
            self.freq[new_freq][1].prev = self.data[key][0]              
            self.freq[new_freq][2] += 1
        self.data[key][1] = new_freq

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if self.capacity == 0:
            return None
        if key in self.data:
            #更新这个值得value和freq
            self.data[key][0].value = value
            self.updatefreq(key)
        else:
            if len(self.data) == self.capacity:
                #找到此时最低频率:self.minfreq
                self.data.pop(self.freq[self.minfreq][0].next.key)
                if self.freq[self.minfreq][2] == 1:
                    self.freq.pop(self.minfreq)
                else:
                    #弹出该频率head节点后的一个
                    self.freq[self.minfreq][2] -= 1
                    self.freq[self.minfreq][0].next = self.freq[self.minfreq][0].next.next
                    self.freq[self.minfreq][0].next.prev = self.freq[self.minfreq][0]
                self.fill_freq_data(key, value)
            else:
                self.fill_freq_data(key, value)
    
    def fill_freq_data(self, key, value):
        self.data[key] = [ListNode(key, value), 1]
        #最低频率变为1 新创建个频率为1 的节点
        if 1 not in self.freq:
            self.freq[1] = [ListNode(), ListNode(), 0]
            self.freq[1][0].next = self.freq[1][1]
            self.freq[1][1].prev = self.freq[1][0]
        self.freq[1][2] += 1
        #从尾部节点加入
        self.minfreq = 1
        m = self.freq[1][1].prev
        m.next = self.data[key][0]
        self.data[key][0].prev = m
        self.data[key][0].next = self.freq[1][1]
        self.freq[1][1].prev = self.data[key][0]     