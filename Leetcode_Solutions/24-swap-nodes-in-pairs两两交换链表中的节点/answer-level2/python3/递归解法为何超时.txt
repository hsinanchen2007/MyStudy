


def track(node):
            
            pivot=node.next 
            if not pivot:
                return node  #不成对子
            behind=pivot.next   #下一对的第一个
            pivot.next=node
            if behind :
                node.next=track(behind)
            return pivot
        return track(head)


为何超时，感觉没啥区别啊