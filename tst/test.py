import numpy as np
from scipy.special import expi


x = np.linspace(-50,50.,10000);

ans = expi(x)

res = np.fromfile('res.dat')

for i,j,k in zip(x,ans,res):
	print(i,j,k)

if np.all(np.isclose(res,ans)):
  print("Pass")
else:
  print("Failed")



import matplotlib.pyplot as plt
fig,ax=plt.subplots()
ax.plot(x, abs((res-ans)/ans),'x')
ax.set_xlabel('$x$')
ax.set_ylabel('Relative Error')
ax.minorticks_on()
ax.set_yscale('log')

fig.tight_layout()
fig.savefig('result.png')


