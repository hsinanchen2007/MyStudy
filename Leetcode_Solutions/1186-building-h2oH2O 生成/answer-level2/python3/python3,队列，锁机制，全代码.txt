def Hydrogen():
	print('H', end='')


def Oxygen():
	print('O', end='')


class H2O:
	def __init__(self):
		self.lock = Lock()
		self.num_h = 0
		self.num_o = 0
		self.release_h = None
		self.release_o = None

	def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
		# releaseHydrogen() outputs "H". Do not change or remove this line.
		self.release_h = releaseHydrogen
		self.control(1, 0)

	def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
		# releaseOxygen() outputs "O". Do not change or remove this line.
		self.release_o = releaseOxygen
		self.control(0, 1)

	def control(self, h, o):
		with self.lock:
			self.num_h += h
			self.num_o += o
			if self.num_h < 2 or self.num_o < 1:
				return
			self.num_h -= 2
			self.num_o -= 1
		self.release_h()
		self.release_h()
		self.release_o()


class H2O1:
	def __init__(self):
		self.h_q, self.o_q = [], []

	def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
		self.h_q.append(releaseHydrogen)
		self.control()

	def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
		self.o_q.append(releaseOxygen)
		self.control()

	def control(self) -> None:
		if len(self.h_q) > 1 and len(self.o_q) > 0:
			self.h_q.pop(0)()
			self.h_q.pop(0)()
			self.o_q.pop(0)()


if __name__ == '__main__':
	input = "OOHHHH"
	h2o = H2O()
	for s in input:
		po = Thread(target=h2o.hydrogen, args=(Hydrogen,))
		ph = Thread(target=h2o.oxygen, args=(Oxygen,))
		po.start()
		ph.start()
