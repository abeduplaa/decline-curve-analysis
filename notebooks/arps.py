import pandas as pd
from scipy.optimize import curve_fit
import numpy as np
import matplotlib.pyplot as plt


def max_qi(df, month_col, interval, prod):
    return df[prod].loc[df[month_col] <= interval].max()



def hyperbolic(t, qi, b, di):
    return qi/((1.0+b*di*t)**(1.0/b))

def exponential(t, qi, di):
    return qi*np.exp(-di*t)


