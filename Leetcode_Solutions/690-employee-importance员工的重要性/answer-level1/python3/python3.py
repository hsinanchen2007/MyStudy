class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        res = {}
        for em in employees:
            res[em.id] = list([em.importance, em.subordinates])
        count = 0
        sub_queue = []

        count += res[id][0]
        for sub in res[id][1]:
            sub_queue.append(sub)
        while sub_queue:
            temp = sub_queue.pop(0)
            count += res[temp][0]
            if res[temp][1]:
                for sub in res[temp][1]:
                    sub_queue.append(sub)
        return count