# $Id: 150_srtp_2_3.py 369517 2012-07-01 17:28:57Z file $
#
from inc_cfg import *

test_param = TestParam(
		"Callee=mandatory SRTP, caller=optional (with duplicated offer) SRTP",
		[
			InstanceParam("callee", "--null-audio --use-srtp=2 --srtp-secure=0 --max-calls=1"),
			InstanceParam("caller", "--null-audio --use-srtp=3 --srtp-secure=0 --max-calls=1")
		]
		)
