class CQueue:

    def __init__(self):
        self.queue = []

    def appendTail(self, value: int) -> None:
        self.queue.append(value)

    def deleteHead(self) -> int:
        if len(self.queue) == 0:
            return -1
        return self.queue.pop(0)