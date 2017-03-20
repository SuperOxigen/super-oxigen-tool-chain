#ifndef _SO_TOOL_CHAIN_
#define _SO_TOOL_CHAIN_

#ifndef __FUNCTION__
#define __FUNCTION__ __func__
#endif /* __FUNCTION__ */

#ifndef lenof
#define lenof(buf) sizeof(buf) / sizeof(*buf)
#endif /* lenof */

#ifdef __GNUC__

#ifndef lambda
#define lambda(return_t, function_body) \
({ return_t __FUNCTION__ ## __LINE__ function_body __FUNCTION__ ## __LINE__; })
#endif /* lambda */

#ifndef _on_end_scope_
#define _on_end_scope_(function_name) __attribute__ ((cleanup(function_name)))
#endif /* _on_end_scope_ */

#endif /* __GNUC__ */

#endif /* _SO_TOOL_CHAIN_ */
