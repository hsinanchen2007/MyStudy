class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if not self.data:
            self.data.append((x, x))
        else:

            mini = min(x, self.min())
            self.data.append((x, mini))

    def pop(self):
        """
        :rtype: None
        """
        self.data.pop()

    def top(self):
        """
        :rtype: int
        """
        x, y = self.data[-1]
        return x


    def min(self):
        """
        :rtype: int
        """
        w, z = self.data[-1]
        return z